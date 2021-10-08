# Ordenando Estudantes
A Universidade Federal de Mato Grosso do Sul possui um banco de dados que armazena todos os estudantes regulares cursando a disciplina de Algoritmos e Programação II. Frequentemente, o professor precisa acessar essa lista de alunos de diferentes maneiras, incluindo ações
como buscar um aluno e imprimir a lista em uma determinada ordem. Infelizmente, o sistema da
universidade foi implementado em 1943 (dois anos antes da publicação do primeiro algoritmo
de ordenação O(n log2 n)). Portanto, o sistema atual costuma ser extremamente lento.
Sabendo que você está cursando a disciplina e os conhecimentos de ordenação e busca
eficientes estão bem sedimentados em sua mente, ficou a seu cargo reimplementar o backend
deste sistema, agora utilizando algoritmos mais eficientes.
## Os estudantes
Os dados de cada estudante são armazenados em um registro (struct) que contém os seguintes
campos:
struct Estudante
{
int RGA;
char nome[];
double media;
};
RGA é um campo que contêm o RGA de cada aluno. nome é o campo que armazena o nome
completo de cada aluno, que pode conter espaços1
. Considere que nenhum aluno possui
nome com mais de 100 caracteres. media é um campo que armazena a média final de cada
aluno na disciplina de Algoritmos e Programação II. Este valor está sempre entre 0.0 e 10.
O Sistema
O sistema que você deve estruturar deve ser capaz de ordenar os estudantes em ordem crescente baseado em cada um dos critérios: RGA, media e nome (para esse último, considere a
ordem lexicográfica). Além disso, o sistema também deve ser capaz de realizar várias buscas
por estudantes baseado em cada um desses fatores.
A sua função de busca deve ter eficiência O(log2 n), e sua ordenação deve ter eficiência
O(n log2 n), considerando n como o tamanho do banco de dados dos estudantes.