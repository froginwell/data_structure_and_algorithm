"""
LeetCode 71. Simplify Path

Given an absolute path for a file (Unix-style), simplify it. Or in other words, convert it to the canonical path.

In a UNIX-style file system, a period . refers to the current directory. Furthermore, a double period .. moves the directory up a level. For more information, see: Absolute path vs relative path in Linux/Unix

Note that the returned canonical path must always begin with a slash /, and there must be only a single slash / between two directory names. The last directory name (if it exists) must not end with a trailing /. Also, the canonical path must be the shortest string representing the absolute path.

 

Example 1:

Input: "/home/"
Output: "/home"
Explanation: Note that there is no trailing slash after the last directory name.
Example 2:

Input: "/../"
Output: "/"
Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.
Example 3:

Input: "/home//foo/"
Output: "/home/foo"
Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.
Example 4:

Input: "/a/./b/../../c/"
Output: "/c"
Example 5:

Input: "/a/../../b/../c//.//"
Output: "/c"
Example 6:

Input: "/a//b////c/d//././/.."
Output: "/a/b/c"
"""


class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        if not path:
            return '/'

        stk = []
        i = 0
        l = len(path)
        while i < l:
            c = path[i]
            if c == '/':
                while i < l - 1:
                    i += 1
                    if path[i] != '/':
                        break
            elif c == '.':
                j = 0
                if i < l - 1 and path[i + 1] == '.':
                    j += 1
                    i += 1
                while i < l - 1:
                    i += 1
                    if path[i] != '/':
                        break
                if j == 1 and stk:
                    stk.pop()
            else:
                name = [c]
                while True and i < l - 1:
                    i += 1
                    if path[i] in ('/', '.'):
                        break
                    else:
                        name.append(path[i])
                stk.append(''.join(name))
            if i == l - 1:
                break

        if stk:
            return '/' + '/'.join(stk)
        return '/'


if __name__ == '__main__':
    s = Solution()
    for path in [
        '/home/',
        '/../',
        '/home//foo/',
        '/a/./b/../../c/',
        '/a/../../b/../c//.//',
        '/a//b////c/d//././/..',
    ]:
        print(s.simplifyPath(path))
