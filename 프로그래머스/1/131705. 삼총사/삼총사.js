function solution(number) {
    var answer = 0;
    var size = number.length;
    for(let i=0;i<size-2;i++){
        let first = number[i];
        for(let j=i+1;j<size-1;j++){
            let second = number[j];
            for(let k=j+1;k<size;k++){
                let third = number[k];
                if(first + second + third === 0) answer++;
            }
        }
    }
    return answer;
}