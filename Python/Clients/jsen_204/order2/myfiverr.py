import time
from pydrive.drive import GoogleDrive
from pydrive.auth import GoogleAuth

import os
import schedule


def upload_file():
    # Below code does the authentication
    # part of the code
    gauth = GoogleAuth()

    if os.path.exists("mycreds.txt"):
        gauth.LoadCredentialsFile("mycreds.txt")

    if gauth.credentials is None:
        # Creates local webserver and auto
        # handles authentication.
        gauth.LocalWebserverAuth()
        # Save credentials to file
        gauth.SaveCredentialsFile("mycreds.txt")
    elif gauth.access_token_expired:
        # Refresh the access token
        gauth.Refresh()
    else:
        # Authorize using the saved credentials
        gauth.Authorize()

    # Creates local webserver and auto
    # handles authentication.
    gauth.LocalWebserverAuth()
    drive = GoogleDrive(gauth)

    # replace the value of this variable
    # with the absolute path of the directory
    path = r"C:/Users/shena/Desktop/Fiverr\original repo\Fiverr\Python\Clients\jsen_204\order2\Test.csv"

    # Search for the file in Google Drive
    file_list = drive.ListFile({'q': "title='Test.csv'"}).GetList()

    if len(file_list) == 0:
        # File doesn't exist, upload it
        f = drive.CreateFile({'title': 'Test.csv'})
        f.SetContentFile(path)
        f.Upload()
    else:
        # File exists, overwrite it
        file_id = file_list[0]['id']
        f = drive.CreateFile({'id': file_id})
        f.SetContentFile(path)
        f.Upload()

    f = None


upload_file()
