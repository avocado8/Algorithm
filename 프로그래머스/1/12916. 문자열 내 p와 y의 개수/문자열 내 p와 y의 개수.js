function solution(s){
    s = s.toLowerCase();
    let cnt_s = 0;
    let cnt_p = 0;
    for(let i=0;i<s.length;i++){
        if(s[i]==="p") cnt_p++;
        else if (s[i]==="y") cnt_s++;
    }
    return cnt_p===cnt_s ? true : false;
}