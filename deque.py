from collections import deque

d = deque()
nums = list(map(int, input().split()))
k = int(input())
d.append(0)
for i in range(1, k):
    if nums[i] >= nums[i - 1]:
        d.pop()
        d.append(i)
print(nums[d[0]], end=" ")

for j in range(k, len(nums)):

    while d and d[0] <= j - k:
        d.popleft()
    while d and nums[j] >= nums[d[-1]]:
        d.pop()
    d.append(j)
    print(nums[d[0]], end=" ")
