-- FICHEIRO arithmetic_unit.vhd

-- Declaração de bibliotecas
library IEEE;
use IEEE.std_logic_1164.all;

-- Definição do nome da entidade e 
-- dos sinais (fios) de entrada/saída
entity arithmetic_unit is
   port (
        A  : in  std_logic_vector(7 downto 0);
        B  : in  std_logic_vector(7 downto 0);
        Op : in  std_logic;
        S  : out std_logic_vector(7 downto 0);
        co : out std_logic;
        V  : out std_logic
        );
end arithmetic_unit;







architecture behavior of arithmetic_unit is
-- declaração do componente somador8
component somador8
   port (
        A  : in  std_logic_vector(7 downto 0);
        B  : in  std_logic_vector(7 downto 0);
        ci : in  std_logic;
        S  : out std_logic_vector(7 downto 0);
        co : out std_logic;
        V  : out std_logic
   );
end component;
-- declaração dos sinais internos
signal X : std_logic_vector(7 downto 0);

begin
-- 8 portas XOR, uma por cada bit
X <= B xor (7 downto 0 => op);
-- instancia do componente somador8
UADD: somador8 port map(
         A => A, B => X, ci => op,
         S => S, V => V, co => co
       );
end behavior;
