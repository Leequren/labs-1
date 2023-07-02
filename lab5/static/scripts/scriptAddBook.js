const button = document.querySelector('button')
button.addEventListener('click', async (event) => {
    event.preventDefault()
    let authorName = document.querySelector('input[name="author"]').value
    let bookName = document.querySelector('input[name="book"]').value
    let genreName = document.querySelector('input[name="genre"]').value
    let referenceGenre = document.querySelector('input[name="reference-genre"]').checked
    let popular = document.querySelector('input[name="popular"]').checked
    console.log(authorName, bookName, genreName, referenceGenre, popular)
    await axios.post('/', {
        authorName: authorName,
        bookName: bookName,
        genreName: genreName,
        referenceGenre: referenceGenre,
        popular: popular
    })
    window.location.reload()
})