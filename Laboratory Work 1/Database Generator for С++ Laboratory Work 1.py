import random
from pathlib import Path

N = int(input())

list_of_surnames = ['Dolce', 'Repetto', 'Franchi', 'Petrucci', 'Lombardo',
                    'Palma', 'Berti', 'Vacca', 'Salvatore', 'Natale', 'Pepe',
                    'Palla', 'Stella', 'Messina', 'Giannini', 'Nygaard', 'Henriksen',
                    'Lund', 'Mogensen', 'Lindegaard', 'Axelsen', 'Schmidt',
                    'Henningsen', 'Lauritsen', 'Lauritzen', 'Frank', 'Astrup',
                    'Beck', 'Laugesen', 'Marcussen']

list_of_names = ['Emil', 'Georg', 'Thor', 'Claus', 'Nicklas', 'Peder', 'Valdemar',
                 'Mads', 'Kim', 'Benjamin', 'Laurits', 'Simon', 'Morten',
                 'Svend', 'Stig', 'Patrice', 'Raphael', 'Pierre-Antoine', 'Julien',
                 'Roland', 'Robert', 'Jean-Christophe', 'Edmond', 'Tristan',
                 'Flavien', 'Gabriel', 'Pierre', 'Antoine', 'Ange', 'Pierre-Yves']

list_of_middlenames = ['Eremeevich', 'Fedosievich', 'Vyacheslavovich', 'Pankratievich',
                       'Adronikovich', 'Venedictovich', 'Valerianovich', 'Adrianovich',
                       'Miheevich', 'Ippolitovich', 'Arhipovich', 'Rostislavovich',
                       'Anatolievich', 'Iosifovich', 'Filimonovich', 'Samsonovich',
                       'Alexandrovich', 'Fomievich', 'Kapitonovich', 'Trofimovich',
                       'Kasyanovich', 'Vladimirovich', 'Bronislavovich', 'Platonovich',
                       'Sevastyanovich', 'Ermolaevich', 'Evlampievich', 'Olegovich',
                       'Pahomovich', 'Potopovich']

list_of_branches = ['Chern', 'Kyzlyar', 'Perevoz', 'Anaheim', 'Okland', 'Karasuk',
                    'Nitra', 'Livingstone', 'Kluj-Napoka', 'Bhopal', 'Gorodische',
                    'Leiden', 'Tyrana', 'Torgau', 'Granada']

list_of_positions = ['Bookmaker', 'Cabinetmaker', 'Technician', 'Watchman', 'Nutritionist',
                     'Pharmacist', 'Analyst', 'Businessman', 'Detective', 'Dispatcher',
                     'Historian', 'Mangaka', 'Ophthalmologist', 'Radiophysicist', 'Swineherd']

path = Path('C:/Users/Artem/source/repos/Project2C++/Project2C++/Accounting.txt')

with open(path, 'w') as f:
    if N != 0:
        f.write(str(N) + '\n')
    for i in range(N):
        f.write(random.choice(list_of_names) + ' ' + random.choice(list_of_surnames) + ' ' +
                random.choice(list_of_middlenames) + ' ' + str(random.randint(0, 1000)) + ' ' +
                random.choice(list_of_branches) + ' ' + random.choice(list_of_positions) + '\n')
