min_n, k, max_t, max_group_size, max_duplicate, seed = gets.split.map(&:to_i)

srand seed # Deterministisk! (Och dynamisk! / osk)

def assert(b)
  if not b then
    puts "Assertion failed yao!"
    exit(1)
  end
end

# resulting n will be at least min_n, and in practice around
# (min_n + max_group_size/2) * (max_duplicate/2 + 1)
n = min_n

t = 0

arrivals = []

while n > 0 do
  t += rand > 0.7 ? rand(k*20) : rand(k*1) # Såhär vi skapar klungor
  t %= max_t - (4*k) # I wanted just max_t, but we are comforty here
  group_size = rand(max_group_size)
  group_size.times {
    arrivals += [ t + rand(2*k) + 1 ] * (rand(max_duplicate) + 1)
  }
  n -= group_size
end

arrivals.shuffle!
# arrivals.sort! # TODO remove

puts "#{arrivals.size} #{k}"
puts arrivals.join(" ")
