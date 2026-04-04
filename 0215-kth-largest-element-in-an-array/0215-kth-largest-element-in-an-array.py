class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        heapq.heapify(nums)
        while len(nums) > k:
            heapq.heappop(nums)

        return nums[0]

        # quickSelect
        # k = len(nums) - k
        
        # def quickSelect(l, r):
        #     rand = random.randint(l, r)
        #     nums[r], nums[rand] = nums[rand], nums[r]

        #     pviot, p = nums[r], l
        #     for i in range(l, r):
        #         if nums[i] <= pviot:
        #             nums[p], nums[i] = nums[i], nums[p]
        #             p += 1
        #     nums[p], nums[r] = nums[r], nums[p]
        #     if k < p : return quickSelect(l, p - 1)
        #     elif k > p : return quickSelect(p + 1, r)
        #     elif k == p : return nums[p]
        
        # return quickSelect(0, len(nums) - 1)