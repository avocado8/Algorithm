function solution(brown, yellow) {
    if (yellow===1) return [yellow+2, yellow+2];
    
    let answer = [];
    // 1 x 24 / 2 x 12 / 3 x 8/ 4 x 6 / 
    //갈색개수: 4 + (노란색가로길이)x2 + (노란색세로길이)x2
    for(let i=1;i<yellow;i++){
        let col = i; //세로길이
        let row = yellow / i //가로길이
        if(col>row || row !== Math.floor(row)) continue;
        let tmp = 4 + row*2 + col*2;
        if(tmp === brown) {
            answer.push(row + 2);
            answer.push(col + 2)
            break;
        }
    }
    return answer;
}