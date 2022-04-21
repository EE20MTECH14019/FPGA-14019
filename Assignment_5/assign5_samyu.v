module assign5_samyu(
input wire p,
input wire q,
input wire r,
output wire redled,
output wire greenled,
output wire blueled
);

reg out;
always @(*)
begin
out = (q | !r) & (!q | r);
if(out ==1)
begin
redled=1;
end
else
begin
redled=0;
end
end
endmodule
