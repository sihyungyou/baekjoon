import java.util.Arrays;

public class Solution {
    public int solution(int p) {
        int answer = 0;

        answer = p + 1;
        String str = "";
        str = String.valueOf(answer);
        str = Integer.toString(answer);
        str = "" + answer;

        while(true) {
            boolean flag = true;
            // System.out.println("now : " + answer);
            // sort
            char[] temp = str.toCharArray();
            Arrays.sort(temp);

            // System.out.println(temp);

            // check duplicate
            for (int i = 0; i < str.length() - 1; i++) {
                if (temp[i] == temp[i+1]) {
                    // System.out.println(temp[i] + " == " + temp[i+1]);
                    // System.out.println("false");
                    flag = false;
                    break;
                }
            }

            if (!flag) {
                // convert back to integer
                answer = Integer.parseInt(str);

                // increase 1, convert to string again
                answer += 1;

                str = String.valueOf(answer);
                str = Integer.toString(answer);
                str = "" + answer;
                // System.out.println(str);

                continue;
            }
            else {
                answer = Integer.parseInt(str);
                break;
            }
        }


        return answer;
    }
}
