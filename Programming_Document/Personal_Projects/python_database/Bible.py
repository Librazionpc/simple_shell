from kjv import KJV 

# ...instantiate...
kjv = KJV("Bible.db")

books = kjv.fetch_books()
for book in books:
    print(book)

chapters = kjv.fetch_chapters(1, 1)
for k, v in chapters.items():
    print(k, v)

verse = kjv.fetch_passage(1, 1, 1, 1)
print(verse)