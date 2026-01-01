class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        digits.reverse()
        size = len(digits)
        digits[0] += 1
        i = 0
        while i < size:
            if digits[i] < 10:
                i += 1
            else:
                if len(digits) == i + 1:
                    digits.append(0)
                digits[i] -= 10
                digits[i + 1] += 1
                i += 1

        digits.reverse()

        return digits