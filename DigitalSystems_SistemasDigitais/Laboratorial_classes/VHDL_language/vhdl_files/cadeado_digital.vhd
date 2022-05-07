----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    12:03:49 10/29/2013 
-- Design Name: 
-- Module Name:    cadeado_digital - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
-- Declaração de bibliotecas com pré-definições
library IEEE;
use IEEE.std_logic_1164.all;

entity cadeado_digital is
   port ( 
         code   : in  std_logic_vector(3 downto 0);
         xopen  : in  std_logic;
         codeOK : out std_logic;
         OK     : out std_logic;
         Err    : out std_logic
         );
end cadeado_digital;

architecture behavioral of cadeado_digital is
-- declaração dos sinais (fios) internos 
-- ao componente
signal OK32, OK10, OK3210 : std_logic;
begin

-- Cálculo do resultado
OK32   <= (not code(3)) and code(2);
OK10   <= code(1) and code(0);
OK3210 <= OK32 and OK10;


-- Atribuição do valor de saída
codeOK <= OK3210;
OK  <= OK3210 and xopen;
Err <= (not OK3210) and xopen;

end behavioral;
