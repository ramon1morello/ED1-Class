# 1º loop:

intervalo 0,N (usando i)
FN: selecionar a posição do vetor

# 2º loop:

intervalo de 0,N-1 (usando j)
FN: compar se o elemento v[j] é maior que v[j+1]

se sim -> vector_swap

# Exemplo:

V{4} = [9,1,4,5]

em i=0
	j[0]>j[1], -> vector_swap
em i=1
	j[1]>j[2], -> vector_swap
...
