program PascalTriangle;
procedure makeLine(var prevLine: array of integer; n: integer);
var left : integer;
var update : integer;
var i : integer;
begin
    left := 0;
    for i := 1 to (n-1) do
    begin
        update := left + prevLine[i];
        left := prevLine[i];
        prevLine[i] := update;
        Write(prevLine[i], ' ')
    end;
    prevLine[n] := 1;
    WriteLn(prevLine[n])
end;
{
    Here you may write helper functions and procedures.
    Please do.
}

var n, i: integer;
var line: array [1..15] of integer; { Complete the array definition... }

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
    end;
end.
