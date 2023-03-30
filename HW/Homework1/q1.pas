program PascalTriangle;
{
    Here you may write helper functions and procedures.
    Please do.
}

var n,i: integer;
var line: array [1..100] of integer; { Complete the array definition... }

begin
line[1] := 1;
{ Initialize 'line' array }
ReadLn(n);
for i := 1 to n do
    begin
        makeLine(line, i)
        {
            Construct the new line and then print it.
        }
    end
end.