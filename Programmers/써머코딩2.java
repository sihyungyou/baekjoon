import java.util.ArrayList;

class Solution {
    public long solution(long n) {
        long answer = 0;

        ArrayList<Long> arr = new ArrayList();

        int i = 2;
        int j = 1;

        long zero = Long.valueOf(0);
        long one = Long.valueOf(1);
        long three = Long.valueOf(3);

        arr.add(zero);
        arr.add(one);
        arr.add(three);

        while(true) {
            if (i == n) {
                answer = arr.get(i);
                break;
            }
            boolean done = false;
            for (j = 1; j < i; j++) {
                // System.out.println(arr.get(i) + arr.get(j));
                arr.add(arr.get(i) + arr.get(j));
                if (i + j == n) {
                    answer = arr.get(i+j);
                    done = true;
                }
            }

            if (done) break;
            else {
                long temp = arr.get(i) * 3;
                i += j;
                arr.add(temp);
            }
        }

        return answer;
    }
}

// 방법 2
class Solution {

    public boolean isPowerOfTwo(long x)
    {
        return (x != 0) && ((x & (x - 1)) == 0);
    }

    public long dfs(long n) {
        if (isPowerOfTwo(n)) {
            // 바로 3의 x승 구해서 return
            long temp = n;
            int x = 3;
            while(temp != 1)  {
                temp /= 2;
                x *= 3;
            }
            x /= 3;
            return x;
        }
        else {
            long val = 3;
            int x = 0;
            for (long i = n-1; i >= 2; i--) {
                if (isPowerOfTwo(i)) {
                    // 2의 제곱을 찾으면 x를 구함
                    long temp = i;
                    while(i != 1) {
                        i /= 2;
                        x++;
                        val *= 3;
                    }
                    break;
                }
            }
            val /= 3;
            System.out.println(x);
            return val + dfs(n - x);
        }
    }
    public long solution(long n) {
        long answer = 0;

        answer = dfs(n);

        return answer;
    }
}
