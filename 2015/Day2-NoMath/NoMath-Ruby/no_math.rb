area = 0
ribbon = 0
File.foreach("input.txt") do |line|
  ##Part 1
  strings = line.split("x")
  numbers = strings.map(&:to_i).sort
  side1 = numbers[0] * numbers[1]
  side2 = numbers[0] * numbers[2]
  side3 = numbers[1] * numbers[2]
  area += 2 * (side1 + side2 + side3) + side1
  
  #Part 2
  ribbon += (numbers[0] + numbers[1]) * 2 
  ribbon += numbers[0] * numbers[1] * numbers[2]
end
puts "The area of wrapping paper is #{area}"
puts "The length of ribbon is #{ribbon}"
