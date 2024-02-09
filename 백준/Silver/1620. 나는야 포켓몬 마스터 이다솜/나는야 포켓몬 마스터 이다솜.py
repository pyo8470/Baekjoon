N,M= map(int,input().split())
import sys
PokemonsDictName = {}
PokemonsDictNum = {}
for i in range(N):
    pokemon = sys.stdin.readline().strip()
    PokemonsDictName[pokemon] = i+1
    PokemonsDictNum[i+1] = pokemon
for i in range(M):
    a = sys.stdin.readline().strip()
    if a.isdigit():
        print(PokemonsDictNum[int(a)])
    else:
        print(PokemonsDictName[a])