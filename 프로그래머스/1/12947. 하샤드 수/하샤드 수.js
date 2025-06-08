function solution(x) {
    let has = Array.from(x.toString().split('')).reduce((acc, cur)=> Number(acc)+Number(cur),0)
    return x % has === 0 ? true : false;
}