-- FICHEIRO cadeado_digital_testbench_C.vhd

-- Declaração de bibliotecas
library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_unsigned.all;

-- Definição da entidade
entity testbench_C is
end testbench_C;

architecture behavior of testbench_C is

-- Declaração do componente 
-- cadeado_digital original
component cadeado_digital
 port ( 
    code   : in  std_logic_vector(3 downto 0);
    xopen   : in  std_logic;
    codeOK : out std_logic;
    OK     : out std_logic;
    Err    : out std_logic
 );
end component;



-- Declaração dos sinais para o testbench
signal code : std_logic_vector(3 downto 0) := "0000";
signal xopen, codeOK, OK, Err : std_logic := '0';

begin

-- Declaração da unidade de teste
utest: cadeado_digital port map (
	code => code, xopen => xopen,
	codeOK => codeOK, OK => OK, Err => Err);

-- descrição do gerador para o sinal code
gen_code: process
begin
   code <= code + 1;
   wait for 10 ns; 
end process;

-- descrição do gerador para o sinal xopen
gen_open: process
begin
   xopen <= not xopen;
   wait for 16*10 ns;
end process;

end behavior;
