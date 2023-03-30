program ChangingPasswords;
type IntegerArray = array ['a'..'z'] of integer;
function buildStringHist(): IntegerArray;
    var hist : IntegerArray;
    var str : string;
    var i : integer;
    var c : char;
    begin
    for c:= 'a' to 'z' do
        hist[c] := 0;
    ReadLn(str);
    for i := 1 to Length(str) do
        hist[str[i]] := hist[str[i]] + 1;
    buildStringHist := hist
    end;
var hist1 : IntegerArray;
var hist2 : IntegerArray;
var isValid : boolean;
var c : char;
begin
    hist1 := buildStringHist();
    hist2 := buildStringHist();
    isValid := TRUE;
    for c := 'a' to 'z' do
    begin
        if ((hist1[c] > 0) and (hist2[c] > 0)) then
        begin
            isValid := FALSE
        end;
    end;
    if isValid = FALSE then
        WriteLn('FALSE')
    else
        WriteLn('TRUE');
    for c := 'a' to 'z' do
    begin
        hist1[c] := hist1[c] + hist2[c];
        if hist1[c] > 0 then
        begin
            WriteLn(c, ' ', hist1[c])
        end
    end
end.