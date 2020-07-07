local function creatsha1()
  -- https://github.com/mpeterv/sha1
  local common = {}

  -- Merges four bytes into a uint32 number.
  function common.bytes_to_uint32(a, b, c, d)
    return a * 0x1000000 + b * 0x10000 + c * 0x100 + d
  end

  -- Splits a uint32 number into four bytes.
  function common.uint32_to_bytes(a)
    local a4 = a % 256
    a = (a - a4) / 256
    local a3 = a % 256
    a = (a - a3) / 256
    local a2 = a % 256
    local a1 = (a - a2) / 256
    return a1, a2, a3, a4
  end

  local ops = {}

  local bytes_to_uint32 = common.bytes_to_uint32
  local uint32_to_bytes = common.uint32_to_bytes

  function ops.uint32_lrot(a, bits)
    local power = 2 ^ bits
    local inv_power = 4294967296 / power
    local lower_bits = a % inv_power
    return (lower_bits * power) + ((a - lower_bits) / inv_power)
  end

  -- Build caches for bitwise `and` and `xor` over bytes to speed up uint32 operations.
  -- Building the cache by simply applying these operators over all pairs is too slow and
  -- duplicates a lot of work over different bits of inputs.
  -- Instead, when building a cache over bytes, for each pair of bytes split both arguments
  -- into two 4-bit numbers, calculate values over these two halves, then join the results into a byte again.
  -- While there are 256 * 256 = 65536 pairs of bytes, there are only 16 * 16 = 256 pairs
  -- of 4-bit numbers, so that building an 8-bit cache given a 4-bit cache is rather efficient.
  -- The same logic is applied recursively to make a 4-bit cache from a 2-bit cache and a 2-bit
  -- cache from a 1-bit cache, which is calculated given the 1-bit version of the operator.

  -- Returns a cache containing all values of a bitwise operator over numbers with given number of bits,
  -- given an operator over single bits.
  -- Value of `op(a, b)` is stored in `cache[a * (2 ^ bits) + b]`.
  local function make_op_cache(bit_op, bits)
    if bits == 1 then
        return {[0] = bit_op(0, 0), bit_op(0, 1), bit_op(1, 0), bit_op(1, 1)}
    end

    local half_bits = bits / 2
    local size = 2 ^ bits
    local half_size = 2 ^ half_bits
    local half_cache = make_op_cache(bit_op, half_bits)

    local cache = {}

    -- The implementation used is an optimized version of the following reference one,
    -- with intermediate calculations reused and moved to the outermost loop possible.
    -- It's possible to reorder the loops and move the calculation of one of the
    -- half-results one level up, but then the cache is not filled in a proper array order
    -- and its access performance suffers.

    -- for a1 = 0, half_size - 1 do
    --    for a2 = 0, half_size - 1 do
    --       for b1 = 0, half_size - 1 do
    --          for b2 = 0, half_size - 1 do
    --             local a = a1 * half_size + a2
    --             local b = b1 * half_size + b2
    --             local v1 = half_cache[a1 * half_size + b1]
    --             local v2 = half_cache[a2 * half_size + b2]
    --             local v = v1 * half_size + v2
    --             cache[a * size + b] = v
    --          end
    --       end
    --    end
    -- end

    for a1 = 0, half_size - 1 do
        local a1_half_size = a1 * half_size

        for a2 = 0, half_size - 1 do
          local a2_size = a2 * half_size
          local a_size = (a1_half_size + a2) * size

          for b1 = 0, half_size - 1 do
              local a_size_plus_b1_half_size = a_size + b1 * half_size
              local v1_half_size = half_cache[a1_half_size + b1] * half_size

              for b2 = 0, half_size - 1 do
                cache[a_size_plus_b1_half_size + b2] = v1_half_size + half_cache[a2_size + b2]
              end
          end
        end
    end

    return cache
  end

  local byte_and_cache = make_op_cache(function(a, b) return a * b end, 8)
  local byte_xor_cache = make_op_cache(function(a, b) return a == b and 0 or 1 end, 8)

  function ops.byte_xor(a, b)
    return byte_xor_cache[a * 256 + b]
  end

  function ops.uint32_xor_3(a, b, c)
    local a1, a2, a3, a4 = uint32_to_bytes(a)
    local b1, b2, b3, b4 = uint32_to_bytes(b)
    local c1, c2, c3, c4 = uint32_to_bytes(c)

    return bytes_to_uint32(
        byte_xor_cache[a1 * 256 + byte_xor_cache[b1 * 256 + c1]],
        byte_xor_cache[a2 * 256 + byte_xor_cache[b2 * 256 + c2]],
        byte_xor_cache[a3 * 256 + byte_xor_cache[b3 * 256 + c3]],
        byte_xor_cache[a4 * 256 + byte_xor_cache[b4 * 256 + c4]]
    )
  end

  function ops.uint32_xor_4(a, b, c, d)
    local a1, a2, a3, a4 = uint32_to_bytes(a)
    local b1, b2, b3, b4 = uint32_to_bytes(b)
    local c1, c2, c3, c4 = uint32_to_bytes(c)
    local d1, d2, d3, d4 = uint32_to_bytes(d)

    return bytes_to_uint32(
        byte_xor_cache[a1 * 256 + byte_xor_cache[b1 * 256 + byte_xor_cache[c1 * 256 + d1]]],
        byte_xor_cache[a2 * 256 + byte_xor_cache[b2 * 256 + byte_xor_cache[c2 * 256 + d2]]],
        byte_xor_cache[a3 * 256 + byte_xor_cache[b3 * 256 + byte_xor_cache[c3 * 256 + d3]]],
        byte_xor_cache[a4 * 256 + byte_xor_cache[b4 * 256 + byte_xor_cache[c4 * 256 + d4]]]
    )
  end

  function ops.uint32_ternary(a, b, c)
    local a1, a2, a3, a4 = uint32_to_bytes(a)
    local b1, b2, b3, b4 = uint32_to_bytes(b)
    local c1, c2, c3, c4 = uint32_to_bytes(c)

    -- (a & b) + (~a & c) has less bitwise operations than (a & b) | (~a & c).
    return bytes_to_uint32(
        byte_and_cache[b1 * 256 + a1] + byte_and_cache[c1 * 256 + 255 - a1],
        byte_and_cache[b2 * 256 + a2] + byte_and_cache[c2 * 256 + 255 - a2],
        byte_and_cache[b3 * 256 + a3] + byte_and_cache[c3 * 256 + 255 - a3],
        byte_and_cache[b4 * 256 + a4] + byte_and_cache[c4 * 256 + 255 - a4]
    )
  end

  function ops.uint32_majority(a, b, c)
    local a1, a2, a3, a4 = uint32_to_bytes(a)
    local b1, b2, b3, b4 = uint32_to_bytes(b)
    local c1, c2, c3, c4 = uint32_to_bytes(c)

    -- (a & b) + (c & (a ~ b)) has less bitwise operations than (a & b) | (a & c) | (b & c).
    return bytes_to_uint32(
        byte_and_cache[a1 * 256 + b1] + byte_and_cache[c1 * 256 + byte_xor_cache[a1 * 256 + b1]],
        byte_and_cache[a2 * 256 + b2] + byte_and_cache[c2 * 256 + byte_xor_cache[a2 * 256 + b2]],
        byte_and_cache[a3 * 256 + b3] + byte_and_cache[c3 * 256 + byte_xor_cache[a3 * 256 + b3]],
        byte_and_cache[a4 * 256 + b4] + byte_and_cache[c4 * 256 + byte_xor_cache[a4 * 256 + b4]]
    )
  end


  local sha1 = {}
  local uint32_lrot = ops.uint32_lrot
  local byte_xor = ops.byte_xor
  local uint32_xor_3 = ops.uint32_xor_3
  local uint32_xor_4 = ops.uint32_xor_4
  local uint32_ternary = ops.uint32_ternary
  local uint32_majority = ops.uint32_majority

  local bytes_to_uint32 = common.bytes_to_uint32
  local uint32_to_bytes = common.uint32_to_bytes

  local sbyte = string.byte
  local schar = string.char
  local sformat = string.format
  local srep = string.rep

  local function hex_to_binary(hex)
    return (hex:gsub("..", function(hexval)
        return schar(tonumber(hexval, 16))
    end))
  end

  -- Calculates SHA1 for a string, returns it encoded as 40 hexadecimal digits.
  function sha1.sha1(str)
    -- Input preprocessing.
    -- First, append a `1` bit and seven `0` bits.
    local first_append = schar(0x80)

    -- Next, append some zero bytes to make the length of the final message a multiple of 64.
    -- Eight more bytes will be added next.
    local non_zero_message_bytes = #str + 1 + 8
    local second_append = srep(schar(0), -non_zero_message_bytes % 64)

    -- Finally, append the length of the original message in bits as a 64-bit number.
    -- Assume that it fits into the lower 32 bits.
    local third_append = schar(0, 0, 0, 0, uint32_to_bytes(#str * 8))

    str = str .. first_append .. second_append .. third_append
    assert(#str % 64 == 0)

    -- Initialize hash value.
    local h0 = 0x67452301
    local h1 = 0xEFCDAB89
    local h2 = 0x98BADCFE
    local h3 = 0x10325476
    local h4 = 0xC3D2E1F0

    local w = {}

    -- Process the input in successive 64-byte chunks.
    for chunk_start = 1, #str, 64 do
        -- Load the chunk into W[0..15] as uint32 numbers.
        local uint32_start = chunk_start

        for i = 0, 15 do
          w[i] = bytes_to_uint32(sbyte(str, uint32_start, uint32_start + 3))
          uint32_start = uint32_start + 4
        end

        -- Extend the input vector.
        for i = 16, 79 do
          w[i] = uint32_lrot(uint32_xor_4(w[i - 3], w[i - 8], w[i - 14], w[i - 16]), 1)
        end

        -- Initialize hash value for this chunk.
        local a = h0
        local b = h1
        local c = h2
        local d = h3
        local e = h4

        -- Main loop.
        for i = 0, 79 do
          local f
          local k

          if i <= 19 then
              f = uint32_ternary(b, c, d)
              k = 0x5A827999
          elseif i <= 39 then
              f = uint32_xor_3(b, c, d)
              k = 0x6ED9EBA1
          elseif i <= 59 then
              f = uint32_majority(b, c, d)
              k = 0x8F1BBCDC
          else
              f = uint32_xor_3(b, c, d)
              k = 0xCA62C1D6
          end

          local temp = (uint32_lrot(a, 5) + f + e + k + w[i]) % 4294967296
          e = d
          d = c
          c = uint32_lrot(b, 30)
          b = a
          a = temp
        end

        -- Add this chunk's hash to result so far.
        h0 = (h0 + a) % 4294967296
        h1 = (h1 + b) % 4294967296
        h2 = (h2 + c) % 4294967296
        h3 = (h3 + d) % 4294967296
        h4 = (h4 + e) % 4294967296
    end

    return sformat("%08x%08x%08x%08x%08x", h0, h1, h2, h3, h4)
  end

  return sha1.sha1
end

local function get_file_data(file, files_hash)
  local data = files_hash[file]
  if not data then
    data = {}
    files_hash[file] = data
  end
  return data
end

local function get_file_size(file, files_hash)
  local data = get_file_data(file, files_hash)
  local size = data[1]
  if not size then 
    size = os.filesize(file)
    data[1] = size
  end
  return size
end

local sha1 = creatsha1()
local function file_sha1(file)
  local data = try {
    function ()
      return io.readfile(file)
    end
  }
  if data then
    return sha1(data)
  end
end

local function get_file_sha1(file, files_hash)
  local data = get_file_data(file, files_hash)
  local sha1 = data[2]
  if not sha1 then 
    sha1 = file_sha1(file)
    data[2] = sha1
  end
  return sha1
end

function is_hash_changed(dependinfo, files_hash)
  local hashs = dependinfo.hashs or {}
  for _, file in ipairs(dependinfo.files) do
    local data = hashs[file] or {}
    local size = get_file_size(file, files_hash)
    if data[1] ~= size then
      print(file, data[1], size)
      return true
    end
    local sha1 = get_file_sha1(file, files_hash)
    if sha1 and data[2] ~= sha1 then
      print(file, data[2], sha1)
      return true
    end
  end
  return false
end

function update_hash(dependinfo, files_hash)
  local hashs = dependinfo.hashs
  if not hashs then
    hashs = {}
    dependinfo.hashs = hashs
  end
  for _, file in ipairs(dependinfo.files) do
    local data = hashs[file]
    if not data then
      data = {}
      hashs[file] = data
    end
    data[1] = get_file_size(file, files_hash)
    data[2] = get_file_sha1(file, files_hash)
  end
end