----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    12:36:39 10/29/2013 
-- Design Name: 
-- Module Name:    cadeado_digital_v2 - Behavioral 
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

-- FICHEIRO cadeado_digital_v2.vhd
-- Declaração de bibliotecas
library IEEE;
use IEEE.std_logic_1164.all;

-- Declaração da entidade
entity cadeado_digital_v2 is
   port ( 
         code   : in  std_logic_vector(3 downto 0);
         xopen  : in  std_logic;
         xclose : in  std_logic;
         clk    : in  std_logic;
         reset  : in  std_logic;
         OK     : out std_logic;
         Err    : out std_logic;
         lock_state : out std_logic
       );
end cadeado_digital_v2;

architecture behavioral of cadeado_digital_v2 is
-- Declaração do componente cadeado_digital
component cadeado_digital
   port ( 
         code   : in  std_logic_vector(3 downto 0);
         xopen  : in  std_logic;
         codeOK : out std_logic;
         OK     : out std_logic;
         Err    : out std_logic
         );
end component;
-- declaração dos sinais internos
signal toggle, toggle_state : std_logic;
signal next_state, current_state : std_logic;

begin

-- Utilização de 1 instancia do "cadeado_digital"
cadeado1: cadeado_digital port map(
              code => code, 
              xopen => toggle, 
              codeOK => open,
              OK => toggle_state,
              Err => Err
   );

-- porta OR
toggle <= xopen and xclose;

-- porta XOR
next_state <= current_state xor toggle_state;

-- FLIP-FLOP tipo D com reset 
current_state <= '0' when reset='1' else 
                 next_state when rising_edge(clk);

-- Atribuição do resultado
lock_state <= current_state;
OK <= toggle_state;

end behavioral;
