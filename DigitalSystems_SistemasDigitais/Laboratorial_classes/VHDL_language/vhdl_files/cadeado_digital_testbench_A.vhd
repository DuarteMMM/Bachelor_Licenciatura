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

-- Gerador de sinais
process
begin
   -- 1ª linha
   code  <= "0000";
   xopen <= '0';
   wait for 10 ns;
   -- 2ª linha
   code  <= "0001";
   xopen <= '0';
   wait for 10 ns;
   -- 3ª linha
   code  <= "0010";
   xopen <= '0';
   wait for 10 ns;
   -- 4ª linha
   code  <= "0011";
   xopen <= '0';
   wait for 10 ns;
   -- 5ª linha
   code  <= "0100";
   xopen <= '0';
   wait for 10 ns;
   -- 6ª linha
   code  <= "0101";
   xopen <= '0';
   wait for 10 ns;
   -- 7ª linha
   code  <= "0110";
   xopen <= '0';
   wait for 10 ns;
   -- 8ª linha
   code  <= "0111";
   xopen <= '0';
   wait for 10 ns;
   -- 9ª linha
   code  <= "1000";
   xopen <= '0';
   wait for 10 ns;
   -- 10ª linha
   code  <= "1001";
   xopen <= '0';
   wait for 10 ns;
   -- 11ª linha
   code  <= "1010";
   xopen <= '0';
   wait for 10 ns;
   -- 12ª linha
   code  <= "1011";
   xopen <= '0';
   wait for 10 ns;
   -- 13ª linha
   code  <= "1100";
   xopen <= '0';
   wait for 10 ns;
   -- 14ª linha
   code  <= "1101";
   xopen <= '0';
   wait for 10 ns;
   -- 15ª linha
   code  <= "1110";
   xopen <= '0';
   wait for 10 ns;
   -- 16ª linha
   code  <= "1111";
   xopen <= '0';
   wait for 10 ns;
   -- 17ª linha
   code  <= "0000";
   xopen <= '1';
   wait for 10 ns;
   -- 18ª linha
   code  <= "0001";
   xopen <= '1';
   wait for 10 ns;
   -- 19ª linha
   code  <= "0010";
   xopen <= '1';
   wait for 10 ns;
   -- 20ª linha
   code  <= "0011";
   xopen <= '1';
   wait for 10 ns;
   -- 21ª linha
   code  <= "0100";
   xopen <= '1';
   wait for 10 ns;
   -- 22ª linha
   code  <= "0101";
   xopen <= '1';
   wait for 10 ns;
   -- 23ª linha
   code  <= "0110";
   xopen <= '1';
   wait for 10 ns;
   -- 24ª linha
   code  <= "0111";
   xopen <= '1';
   wait for 10 ns;
   -- 25ª linha
   code  <= "1000";
   xopen <= '1';
   wait for 10 ns;
   -- 26ª linha
   code  <= "1001";
   xopen <= '1';
   wait for 10 ns;
   -- 27ª linha
   code  <= "1010";
   xopen <= '1';
   wait for 10 ns;
   -- 28ª linha
   code  <= "1011";
   xopen <= '1';
   wait for 10 ns;
   -- 29ª linha
   code  <= "1100";
   xopen <= '1';
   wait for 10 ns;
   -- 30ª linha
   code  <= "1101";
   xopen <= '1';
   wait for 10 ns;
   -- 31ª linha
   code  <= "1110";
   xopen <= '1';
   wait for 10 ns;
   -- 32ª linha
   code  <= "1111";
   xopen <= '1';
   wait;
end process;

END;
