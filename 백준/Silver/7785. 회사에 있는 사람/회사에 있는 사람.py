N = int(input())
people = set()
for i in range(N):
    person, goOut = input().split()
    if goOut == "enter":
        people.add(person)
    else :
        if person in people:
            people.remove(person)
        continue
people = list(people)
people.sort(reverse=True)
for i in people:
    print(i)