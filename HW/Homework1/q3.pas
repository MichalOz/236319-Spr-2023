program Q3;
function P(a:integer; b:integer; c:integer):boolean;
begin
    if (a*a) + (b*b) = (c*c) then P:= True else P:=False;
end;

function Caesar(ch:char; d:integer):char;
var asciiVal:integer;
begin
    asciiVal:=Ord(ch)+d;
    Caesar:= Chr(asciiVal)
end;

function G(hw:integer; exam:integer):integer;
begin
    if exam<=54 then G:=exam else G:= Round((0.8*exam)+(0.2*hw));
end;

var i, j, a, b, cc, d, hw, exam:integer;
var input:array [0..4] of char;
var ch:char;
var outC:array [0..2] of char;
var outP:array [0..2] of boolean;
var outG:array [0..2] of integer;
var Ci,Pi,Gi:integer;

begin
    Ci:=2;
    Gi:=2;
    Pi:=2;
    for i:=0 to 4 do
        ReadLn(input[i]);

    for i:=0 to 4 do
    begin
        case input[i] of
            'P': 
            begin
                ReadLn(a);
                ReadLn(b);
                ReadLn(cc);
                outP[Pi]:=P(a,b,cc);
                Pi:=Pi-1
            end;
            'C':
            begin
                ReadLn(ch);
                ReadLn(d);
                outC[Ci]:=Caesar(ch,d);
                Ci:=Ci-1
            end;
            'G':
            begin
                ReadLn(hw);
                ReadLn(exam);
                outG[Gi]:=G(hw,exam);
                Gi:=Gi-1
            end
        end
    end;

    Ci:=Ci+1;
    Gi:=Gi+1;
    Pi:=Pi+1;

    for j:=4 downto 0 do
    begin
        case input[j] of
            'P': 
            begin
                WriteLn(outP[Pi]);
                Pi:=Pi+1
            end;
            'C':
            begin
                WriteLn(outC[Ci]);
                Ci:=Ci+1
            end;
            'G':
            begin
                WriteLn(outG[Gi]);
                Gi:=Gi+1
            end;
        end
    end
end.