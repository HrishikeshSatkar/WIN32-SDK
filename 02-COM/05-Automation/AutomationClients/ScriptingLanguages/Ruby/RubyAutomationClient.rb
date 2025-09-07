require 'win32ole'

objMyMath = WIN32OLE.new('{F2D89068-14C0-4C09-8679-2E620D81DF44}')

num1 = 200
num2 = 100

resultAddition = objMyMath.SumOfTwoIntegers(num1,num2);
puts "#{num1} + #{num2} = #{resultAddition}"

resultSubstraction = objMyMath.SubtractionOfTwoIntegers(num1,num2);
puts "#{num1} - #{num2} = #{resultSubstraction}"