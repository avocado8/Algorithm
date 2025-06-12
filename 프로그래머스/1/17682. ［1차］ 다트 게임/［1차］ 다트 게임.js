function getMul(c){
    if(c==="S") return 1;
    else if(c==="D") return 2;
    else return 3;
}

function solution(dartResult) {
    let idx = 0;
    let score = [];
    let tmp = 0;
    while(idx < dartResult.length){
        let cmd = dartResult[idx];
        if(cmd==="*"){
            console.log("* now score", score);
            score[score.length - 1] *= 2;
            if(score.length >= 2){
                score[score.length - 2] *= 2;
            }
        }
        else if(cmd==="#"){
            console.log("# now score", score);
            score[score.length - 1] *= -1;
            
        }
        else {
            if(dartResult[idx+1]==="0"){
                cmd = "10";
                idx++;
            }
            idx++;
            let multiple = dartResult[idx];
            // console.log("multiple is"+multiple);
            score.push(Number(cmd) ** getMul(multiple))
        }
        idx++;
    }
    console.log(score);
    
    return score.reduce((acc, cur)=>acc+cur, 0);
}