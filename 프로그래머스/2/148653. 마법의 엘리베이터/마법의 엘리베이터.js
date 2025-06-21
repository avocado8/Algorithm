function solution(storey) {
    let answer = 0;
    while(storey > 0){
        let rest = storey % 10;
        if(rest !== 0){
            if(rest > 5){
                answer += (10 - rest);
                storey = Math.floor(storey / 10) + 1;
            }
            else if(rest === 5) { // 다음자리 보고 판단
                answer += 5;
                let next = Math.floor(storey / 10) % 10;
                if(next >= 5){ // 올림
                    storey = Math.floor(storey / 10) + 1;
                } else storey = Math.floor(storey/10); // 버림
            }
            else {
                answer += rest;
                storey = Math.floor(storey/10);
            }
        }
        else storey = Math.floor(storey/10);
    }
    return answer;
}

// 2554
// 2550 4
// 2600 5
// 3000 4
// 0 3

// 2544
// 2540 4
// 2500 4
