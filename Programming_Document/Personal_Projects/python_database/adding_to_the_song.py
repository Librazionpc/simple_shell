import os
from sqlalchemy import create_engine
from sqlalchemy.orm import sessionmaker
from Songs import Song

# Function to add songs from files in a directory to the database
def add_songs_from_directory(session, directory):
    if not os.path.exists(directory):
        print(f"Directory '{directory}' does not exist.")
        return
    
    for filename in os.listdir(directory):
        if filename.endswith(".txt"):
            Song.add_song_from_file(session, filename, directory)
        else:
            Song.add_song_from_file(session, filename, directory)

# Function to print all songs in the database
# Create a database engine
engine = create_engine('sqlite:///songs.db', echo=True)

# Create all defined tables in the database
Song.metadata.create_all(engine)

# Create a sessionmaker
Session = sessionmaker(bind=engine)

# Create a session
session = Session()

search_title = input("Enter Song Title ")
matching_songs = Song.search_song(session, search_title)

if matching_songs:
    print("matching_songs.....")
    
    for i, song in enumerate(matching_songs, start=1):
        print(f"{i}, {song.title}")
        
    selection = int(input("Enter the number: "))
    if 1 <= selection <= len(matching_songs):
        selected_song = matching_songs[selection - 1]
        print(f"Selected song: {selected_song.title} - {selected_song.content}")
    else:
        print("Invalid selection.")
else:
    print("No matching songs found.")
# Close the session
session.close()
