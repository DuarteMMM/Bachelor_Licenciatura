--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   17:50:50 10/29/2013
-- Design Name:   
-- Module Name:   /home/pfzt/xilinx/sdlab/cadeado_digital_testbench.vhd
-- Project Name:  sdlab
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: cadeado_digital
-- 
-- Dependencies:
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
--
-- Notes: 
-- This testbench has been automatically generated using types std_logic and
-- std_logic_vector for the ports of the unit under test.  Xilinx recommends
-- that these types always be used for the top-level I/O of a design in order
-- to guarantee that the testbench will bind correctly to the post-implementation 
-- simulation model.
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY cadeado_digital_testbench IS
END cadeado_digital_testbench;
 
ARCHITECTURE behavior OF cadeado_digital_testbench IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT cadeado_digital
    PORT(
         code : IN  std_logic_vector(3 downto 0);
         xopen : IN  std_logic;
         codeOK : OUT  std_logic;
         OK : OUT  std_logic;
         Err : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal code : std_logic_vector(3 downto 0) := (others => '0');
   signal xopen : std_logic := '0';

 	--Outputs
   signal codeOK : std_logic;
   signal OK : std_logic;
   signal Err : std_logic;
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: cadeado_digital PORT MAP (
          code => code,
          xopen => xopen,
          codeOK => codeOK,
          OK => OK,
          Err => Err
        ); 

-- Gerador do sinal code
process
begin
   -- 1ª linha
   code  <= "0000";
   wait for 10 ns;
   -- 2ª linha
   code  <= "0001";
   wait for 10 ns;
   -- 3ª linha
   code  <= "0010";
   wait for 10 ns;
   -- 4ª linha
   code  <= "0011";
   wait for 10 ns;
   -- 5ª linha
   code  <= "0100";
   wait for 10 ns;
   -- 6ª linha
   code  <= "0101";
   wait for 10 ns;
   -- 7ª linha
   code  <= "0110";
   wait for 10 ns;
   -- 8ª linha
   code  <= "0111";
   wait for 10 ns;
   -- 9ª linha
   code  <= "1000";
   wait for 10 ns;
   -- 10ª linha
   code  <= "1001";
   wait for 10 ns;
   -- 11ª linha
   code  <= "1010";
   wait for 10 ns;
   -- 12ª linha
   code  <= "1011";
   wait for 10 ns;
   -- 13ª linha
   code  <= "1100";
   wait for 10 ns;
   -- 14ª linha
   code  <= "1101";
   wait for 10 ns;
   -- 15ª linha
   code  <= "1110";
   wait for 10 ns;
   -- 16ª linha
   code  <= "1111";
   wait for 10 ns;
end process;

-- Gerador do sinal code
process
begin
	xopen <= '0';
	wait for 16*10 ns;
	xopen <= '1';
	wait for 16*10 ns;
end process;

END;
