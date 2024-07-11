library IEEE;
use IEEE.STD_LOGIC_1164.all;
 
entity mux_4to1 is
 port(
 
     i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11,i12,i13,i14,i15: in STD_LOGIC;
     S0,S1,S2,S3: in STD_LOGIC;
     Z: out STD_LOGIC
  );
end mux_4to1;


architecture bhv of mux_4to1 is
begin

process (i0,i1,i2,i3,S0,S1) is
begin
  if (S3 ='0' and S2 = '0' and S1 ='0' and S0 = '0') then
      Z <= i0;
  elsif (S3 ='0' and S2 = '0' and S1 ='0' and S0 = '1') then
      Z <= i1;
  elsif (S3 ='0' and S2 = '0' and S1 ='1' and S0 = '0') then
      Z <= i2;
  elsif (S3 ='0' and S2 = '0' and S1 ='1' and S0 = '1') then
      Z <= i3;
  elsif (S3 ='0' and S2 = '1' and S1 ='0' and S0 = '0') then
      Z <= i4;
  elsif (S3 ='0' and S2 = '1' and S1 ='0' and S0 = '1') then
      Z <= i5;
  elsif (S3 ='0' and S2 = '1' and S1 ='1' and S0 = '0') then
      Z <= i6;
  elsif (S3 ='0' and S2 = '1' and S1 ='1' and S0 = '1') then
      Z <= i7;
  elsif (S3 ='1' and S2 = '0' and S1 ='0' and S0 = '0') then
      Z <= i8;
  elsif (S3 ='1' and S2 = '0' and S1 ='0' and S0 = '1') then
      Z <= i9;
  elsif (S3 ='1' and S2 = '0' and S1 ='1' and S0 = '0') then
      Z <= i10;
  elsif (S3 ='1' and S2 = '0' and S1 ='1' and S0 = '1') then
      Z <= i11;
  elsif (S3 ='1' and S2 = '1' and S1 ='0' and S0 = '0') then
      Z <= i12;
  elsif (S3 ='1' and S2 = '1' and S1 ='0' and S0 = '1') then
      Z <= i13;
  elsif (S3 ='1' and S2 = '1' and S1 ='1' and S0 = '0') then
      Z <= i14;
  else
      Z <= i15;
  end if;

end process;
end bhv;

