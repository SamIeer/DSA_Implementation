const tog = document.getElementById('but');
const sildbar = document.getElementById('sidebar');
const main = document.getElementById('container');

tog.addEventListener("click", ()=>{
    const menu = document.getElementById('bar1');
    const croox = document.getElementById('bar2');
    if(menu.style.display == 'none'){
        menu.style.display = 'block';
        croox.style.display = 'none';
        sildbar.style.display = 'none';
        main.style.marginLeft = '0px';
    } else{
        menu.style.display = 'none';
        croox.style.display = 'block';
        sildbar.style.display = 'block';
        main.style.marginLeft = '180px';
    }
    
});

document.querySelectorAll('.copy-button').forEach(button => {
    button.addEventListener('click', () => {
        const targetId = button.getAttribute('data-target');
        const codeElement = document.getElementById(targetId);
        const codeText = codeElement.textContent;

        navigator.clipboard.writeText(codeText).then(() => {
            button.textContent = 'Copied!';
            setTimeout(() => {
                button.textContent = 'Copy';
            }, 2000);
        }).catch(err => {
            console.error('Failed to copy: ', err);
        });
    });
});