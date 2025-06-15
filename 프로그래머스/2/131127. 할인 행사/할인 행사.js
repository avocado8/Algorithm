function solution(want, number, discount) {
    let answer = 0;
    for(let i=0;i<=discount.length-10;i++){
        let tmp_num = [...number];
        if(!want.find((el)=>el===discount[i])) {
            continue;
        }
        for(let j=i;j<i+10;j++){
            let idx = want.findIndex((el)=>el===discount[j]);
            if(idx>=0) tmp_num[idx]--;
        }
        if(tmp_num.every((el)=>el===0)) answer++;
    }
    return answer;
}