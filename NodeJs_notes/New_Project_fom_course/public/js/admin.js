const deleteProduct = (btn) => {
    // console.log(btn.parentNode.querySelector('[name=productId]'));
    const productId = btn.parentNode.querySelector('[name=productId]').value;
    const csrf = btn.parentNode.querySelector('[name=_csrf]').value;

    // get the closest article tag dom
    const productElement = btn.closest('article');

    console.log("clicked");
    fetch('/admin/product/' + productId, {
        method: 'DELETE',
        headers: {
            'csrf-token': csrf
        }
    }).then(result => {
        console.log(result);
        return result.json();
    }).then(data=>{
        console.log(data);
        productElement.parentNode.removeChild(productElement);
        // removing the closest article to the btn --> the current Product DOM
    })
    .catch(err => {
        console.log(err);
    })
}