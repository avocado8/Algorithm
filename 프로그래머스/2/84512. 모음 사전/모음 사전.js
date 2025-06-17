function solution(word) {
    const dict = [];
    const alps = ['A', 'E', 'I', 'O', 'U'];
    
    function dfs(cur){
        if(cur.length > 5) return;
        dict.push(cur);
        for(let alp of alps){
            dfs(cur+alp);
        }
    }
    
    dfs('');
    return dict.findIndex((w)=>w===word);
}