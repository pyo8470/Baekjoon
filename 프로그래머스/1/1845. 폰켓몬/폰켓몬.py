def solution(nums):
    n = len(nums)//2
    Poke = len(set(nums))
    return min(Poke,n)