function solution(weights) {
    const map = new Map();
    const ratios = [[1,1], [2,3], [3,2], [2,4], [4,2], [3,4], [4,3]];
    var answer = 0;
    for(let w of weights){
        for(let [a,b] of ratios){
            let target = (w*b)/a; //비율
            if(map.has(target)){
                answer += map.get(target);
            }
        }
        map.set(w, (map.get(w)||0)+1); //몸무게 기록
    }
    return answer;
}

// 180 : 360 = 2 : 4