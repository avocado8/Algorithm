function solution(topping) {
    let answer = 0;
    let right_count = new Map();
    for(let t of topping){
        right_count.set(t, (right_count.get(t)||0)+1);
    }
    let left_count = new Map();
    for(let i=0;i<topping.length;i++){
        const t = topping[i];
        //인덱스 하나씩 이동하며 개수세기
        left_count.set(t, (left_count.get(t)||0)+1); //왼쪽에선 해당 토핑 개수 하나 추가
        right_count.set(t, right_count.get(t)-1); //오른쪽에선 하나 감소
        if(right_count.get(t)===0) right_count.delete(t);
        if(left_count.size === right_count.size) answer++;
    }
    
    return answer;
}