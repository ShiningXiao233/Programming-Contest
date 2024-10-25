class Solution(object):

    def get_k(self, nums : list[int], l : int, r : int, k : int) -> int:
        x = nums[r]
        ml, mr = l, r
        idx = l 
        while idx <= mr:
            # print(idx, mr)
            if nums[idx] > x:
                nums[ml], nums[idx] = nums[idx], nums[ml]
                ml += 1
                idx += 1
            elif nums[idx] < x:
                nums[idx], nums[mr] = nums[mr], nums[idx]
                mr -= 1
            else:
                idx += 1
        if k >= ml and k <= mr:
            return x
        if k < ml:
            return self.get_k(nums, l, ml - 1, k)
        if k > mr:
            return self.get_k(nums, mr + 1, r, k)

        pass

    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        import random
        random.shuffle(nums)
        lenx = len(nums)
        k -= 1
        return self.get_k(nums, 0, lenx - 1, k)

