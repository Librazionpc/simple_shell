#!/usr/bin/python3

import os
from sqlalchemy import create_engine, Integer, String, Text, Column
from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy.orm import sessionmaker


Base = declarative_base()
class Song(Base):
    __tablename__ = "songs"

    id = Column(Integer, primary_key=True, autoincrement=True)
    title = Column(String(255), nullable=False)
    content = Column(Text)
    
    @classmethod
    def add_song_from_file(cls, session, filename, directory):
        """
        Add a song to the database from a text file if it does not already exist.
        :param filename: The filename of the text file containing the song.
        :param directory: The directory containing the text file.
        """
        # Check if the song with the same title already exists
        existing_song = session.query(cls).filter_by(title=filename).first()
        if existing_song:
            print(f"Song '{filename}' already exists in the database. Skipping...")
            return
        
        with open(os.path.join(directory, filename), 'r') as file:
            content = file.read()
            new_song = cls(title=filename, content=content)
            session.add(new_song)
            session.commit()

    @classmethod
    def get_all_songs(cls, session):
        """
        Retrieve all songs from the database.
        :return: A list of all songs in the database.
        """
        return session.query(cls).all()
    
    @classmethod
    def get_all_songs_title(cls, session):
        """
        Retrieve all songs from the database.
        :return: A list of all songs title in the database.
        """
        return [song.title for song in session.query(cls).all()]
    
    @classmethod
    def search_song(cls, session, title):
        """
        Search the database for a song by title.
        :param title: The title of the song to search for.
        :return: The song object if found, otherwise None.
        """
        
        songs = session.query(cls).filter(cls.title.like(f"%{title}%")).all()
        return songs