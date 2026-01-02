exports.get404error = (req, res, next)=>{
    // res.status(404).send('<h1>Page Not Found</h1>');
    // res.status(404).sendFile(path.join(__dirname, 'views', 'error404-page.html'));
    res.render('error404-page', {docTitle: 'Page Not Found',path: '/404'});
}