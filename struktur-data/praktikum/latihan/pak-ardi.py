# Dolby LL(Cetak)

def createNewSong(titlr):
    return {'title': title, 'prev':None, 'next':None}

def addSongHead(playlist, title):
    newSong = createNewSong(title)
    if playlist is None:
        return newSong
    newSong['next'] = playlist
    playlist['prev'] = newSong
    return newSong

def addSongAtTail(playlist, title):
    newSong = createNewSong(title)
    if playlist is None:
        return newSong
    else:
        temp = playlist
        while temp['next'] != None:
            temp = temp['next']
        temp['next'] = newSong
        newSong['prev'] = temp
        return playlist
