package com.company;

import java.util.ArrayList;
import java.util.List;
class Solution {
    public List<Integer> getRow(int rowIndex) {
        List<Integer> r = new ArrayList<>();
        if(rowIndex+1 <= 0)
            return r;

        //第0 行
        r.add(1);

        for (int i=1; i<rowIndex+1; i++){

            //获取i-1行
            List<Integer> linePre = r;
            r = new ArrayList<>();

            //将1放到这一行的0号位置
            r.add(1);

            //遍历第i-1行，计算出结果，放到第i行最后
            for (int j=0; j<linePre.size()-1; j++){
                r.add(linePre.get(j)+linePre.get(j+1));
            }
            r.add(1);
        }
        return r;

    }

}
