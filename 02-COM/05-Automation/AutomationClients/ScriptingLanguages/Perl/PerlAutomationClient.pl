use Win32::OLE;
my $obj = Win32::OLE->new("{F2D89068-14C0-4C09-8679-2E620D81DF44}");

my $num1 = 500;
my $num2 = 250;

my $resultAddition = $obj->SumOfTwoIntegers($num1,$num2);
print "$num1 + $num2 = $resultAddition\n";

my $resultSubtraction = $obj->SubtractionOfTwoIntegers($num1,$num2);
print "$num1 - $num2 = $resultSubtraction\n";
