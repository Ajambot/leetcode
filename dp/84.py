class Solution:
    def largestRectangleArea(self, heights: list[int]) -> int:
        st = []
        maxH = 0
        for i, h in enumerate(heights):
            if not st or st[-1][0] < h:
                st.append((h, i))
            else:
                lastI = -1
                while st and st[-1][0] > h:
                    pH, pW = st[-1][0], i-st[-1][1]
                    maxH = max(maxH, pW*pH)
                    lastI = st[-1][1]
                    st.pop()
                if lastI != -1:
                    st.append((h, lastI))
        while st:
            h, w = st[-1][0], len(heights)-st[-1][1]
            maxH = max(maxH, w*h)
            st.pop()
        return maxH
