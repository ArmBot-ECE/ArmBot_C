# Armbot_C

## Table of contents
* [Repository overview](#Repository overview)
* [Developper section](#Developper section)


## Project Goal

'*Duchenne muscular dystrophy (DMD) is a genetic disorder characterized by progressive muscle degeneration and weakness due to the alterations of a protein called dystrophin that helps keep muscle cells intact*'. 

([Muscular Dystrophy Association](https://www.mda.org/disease/duchenne-muscular-dystrophy) - Duchenne Muscular Dystrophy (DMD) - Diseases (2021, April 29))

Approximately 4.78 people out of 100,000 possess the DMD in the world. To help those people improve their autonomy, we decided to create a robotic arm, accessible and customizable. Our goal was to create an arm, controllable with an android app, and under a ~400€ budget, using a 3D printer. 

This project was possible thanks to [Niryo](https://niryo.com/fr/)'s 3D models of the arm, the FabLab of [ECE Paris](https://www.ece.fr/) school and [HandiTech](https://handitech-france.fr/).

**The usage of the arm is under the responsability of the user.**

To learn how to use our arm, please go through our [course](https://rise.articulate.com/share/YxWGhuafWEo22Ty-tBzGM7W94fOSDhKb#/).

You'll find further informations in our GitHub and all the ressources in the following [link](https://drive.google.com/drive/folders/1EEAC_9meE7mFTIsfq7AG75mwahTAs3Wy?usp=sharing).

Finally, dont miss to visit our [YouTube](https://www.youtube.com/channel/UCcuagSu5sPNIdyUf5VJzb_w) page.

## Repository overview

All this code must be implemented in a Raspberry Pi 3/4 in order to control all motors and sensors of the robotic arm ArmBot.
You can find all source code structured in a model/controller.

All this code is cloned and automatically compiled by the configuration scripts we have developped for this project.
You can find these scripts in this [repository](https://github.com/ArmBot-ECE/ArmBot_Raspberry).

Please follow instructions from this repository in order to properly use, in a user friendly manner, this C code.

## Developper section

Code compiler used is **gcc**. You can compile code with :

	gcc -o main main.c -lwiringPi -lrt -lpthread -lm -lrt -lcrypt -lbluetooth


