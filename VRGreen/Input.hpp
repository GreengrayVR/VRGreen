#pragma once

enum KeyCode
{
	// Token: 0x04000544 RID: 1348
	None,
	// Token: 0x04000545 RID: 1349
	Backspace = 8,
	// Token: 0x04000546 RID: 1350
	Delete = 127,
	// Token: 0x04000547 RID: 1351
	Tab = 9,
	// Token: 0x04000548 RID: 1352
	Clear = 12,
	// Token: 0x04000549 RID: 1353
	Return,
	// Token: 0x0400054A RID: 1354
	Pause = 19,
	// Token: 0x0400054B RID: 1355
	Escapee = 27,
	// Token: 0x0400054C RID: 1356
	Space = 32,
	// Token: 0x0400054D RID: 1357
	Keypad0 = 256,
	// Token: 0x0400054E RID: 1358
	Keypad1,
	// Token: 0x0400054F RID: 1359
	Keypad2,
	// Token: 0x04000550 RID: 1360
	Keypad3,
	// Token: 0x04000551 RID: 1361
	Keypad4,
	// Token: 0x04000552 RID: 1362
	Keypad5,
	// Token: 0x04000553 RID: 1363
	Keypad6,
	// Token: 0x04000554 RID: 1364
	Keypad7,
	// Token: 0x04000555 RID: 1365
	Keypad8,
	// Token: 0x04000556 RID: 1366
	Keypad9,
	// Token: 0x04000557 RID: 1367
	KeypadPeriod,
	// Token: 0x04000558 RID: 1368
	KeypadDivide,
	// Token: 0x04000559 RID: 1369
	KeypadMultiply,
	// Token: 0x0400055A RID: 1370
	KeypadMinus,
	// Token: 0x0400055B RID: 1371
	KeypadPlus,
	// Token: 0x0400055C RID: 1372
	KeypadEnter,
	// Token: 0x0400055D RID: 1373
	KeypadEquals,
	// Token: 0x0400055E RID: 1374
	UpArrow,
	// Token: 0x0400055F RID: 1375
	DownArrow,
	// Token: 0x04000560 RID: 1376
	RightArrow,
	// Token: 0x04000561 RID: 1377
	LeftArrow,
	// Token: 0x04000562 RID: 1378
	Insert,
	// Token: 0x04000563 RID: 1379
	Home,
	// Token: 0x04000564 RID: 1380
	End,
	// Token: 0x04000565 RID: 1381
	PageUp,
	// Token: 0x04000566 RID: 1382
	PageDown,
	// Token: 0x04000567 RID: 1383
	F1,
	// Token: 0x04000568 RID: 1384
	F2,
	// Token: 0x04000569 RID: 1385
	F3,
	// Token: 0x0400056A RID: 1386
	F4,
	// Token: 0x0400056B RID: 1387
	F5,
	// Token: 0x0400056C RID: 1388
	F6,
	// Token: 0x0400056D RID: 1389
	F7,
	// Token: 0x0400056E RID: 1390
	F8,
	// Token: 0x0400056F RID: 1391
	F9,
	// Token: 0x04000570 RID: 1392
	F10,
	// Token: 0x04000571 RID: 1393
	F11,
	// Token: 0x04000572 RID: 1394
	F12,
	// Token: 0x04000573 RID: 1395
	F13,
	// Token: 0x04000574 RID: 1396
	F14,
	// Token: 0x04000575 RID: 1397
	F15,
	// Token: 0x04000576 RID: 1398
	Alpha0 = 48,
	// Token: 0x04000577 RID: 1399
	Alpha1,
	// Token: 0x04000578 RID: 1400
	Alpha2,
	// Token: 0x04000579 RID: 1401
	Alpha3,
	// Token: 0x0400057A RID: 1402
	Alpha4,
	// Token: 0x0400057B RID: 1403
	Alpha5,
	// Token: 0x0400057C RID: 1404
	Alpha6,
	// Token: 0x0400057D RID: 1405
	Alpha7,
	// Token: 0x0400057E RID: 1406
	Alpha8,
	// Token: 0x0400057F RID: 1407
	Alpha9,
	// Token: 0x04000580 RID: 1408
	Exclaim = 33,
	// Token: 0x04000581 RID: 1409
	DoubleQuote,
	// Token: 0x04000582 RID: 1410
	Hash,
	// Token: 0x04000583 RID: 1411
	Dollar,
	// Token: 0x04000584 RID: 1412
	Percent,
	// Token: 0x04000585 RID: 1413
	Ampersand,
	// Token: 0x04000586 RID: 1414
	Quote,
	// Token: 0x04000587 RID: 1415
	LeftParen,
	// Token: 0x04000588 RID: 1416
	RightParen,
	// Token: 0x04000589 RID: 1417
	Asterisk,
	// Token: 0x0400058A RID: 1418
	Plus,
	// Token: 0x0400058B RID: 1419
	Comma,
	// Token: 0x0400058C RID: 1420
	Minus,
	// Token: 0x0400058D RID: 1421
	Period,
	// Token: 0x0400058E RID: 1422
	Slash,
	// Token: 0x0400058F RID: 1423
	Colon = 58,
	// Token: 0x04000590 RID: 1424
	Semicolon,
	// Token: 0x04000591 RID: 1425
	Less,
	// Token: 0x04000592 RID: 1426
	Equals,
	// Token: 0x04000593 RID: 1427
	Greater,
	// Token: 0x04000594 RID: 1428
	Question,
	// Token: 0x04000595 RID: 1429
	At,
	// Token: 0x04000596 RID: 1430
	LeftBracket = 91,
	// Token: 0x04000597 RID: 1431
	Backslash,
	// Token: 0x04000598 RID: 1432
	RightBracket,
	// Token: 0x04000599 RID: 1433
	Caret,
	// Token: 0x0400059A RID: 1434
	Underscore,
	// Token: 0x0400059B RID: 1435
	BackQuote,
	// Token: 0x0400059C RID: 1436
	A,
	// Token: 0x0400059D RID: 1437
	B,
	// Token: 0x0400059E RID: 1438
	C,
	// Token: 0x0400059F RID: 1439
	D,
	// Token: 0x040005A0 RID: 1440
	E,
	// Token: 0x040005A1 RID: 1441
	F,
	// Token: 0x040005A2 RID: 1442
	G,
	// Token: 0x040005A3 RID: 1443
	H,
	// Token: 0x040005A4 RID: 1444
	I,
	// Token: 0x040005A5 RID: 1445
	J,
	// Token: 0x040005A6 RID: 1446
	K,
	// Token: 0x040005A7 RID: 1447
	L,
	// Token: 0x040005A8 RID: 1448
	M,
	// Token: 0x040005A9 RID: 1449
	N,
	// Token: 0x040005AA RID: 1450
	O,
	// Token: 0x040005AB RID: 1451
	P,
	// Token: 0x040005AC RID: 1452
	Q,
	// Token: 0x040005AD RID: 1453
	R,
	// Token: 0x040005AE RID: 1454
	S,
	// Token: 0x040005AF RID: 1455
	T,
	// Token: 0x040005B0 RID: 1456
	U,
	// Token: 0x040005B1 RID: 1457
	V,
	// Token: 0x040005B2 RID: 1458
	W,
	// Token: 0x040005B3 RID: 1459
	X,
	// Token: 0x040005B4 RID: 1460
	Y,
	// Token: 0x040005B5 RID: 1461
	Z,
	// Token: 0x040005B6 RID: 1462
	LeftCurlyBracket,
	// Token: 0x040005B7 RID: 1463
	Pipe,
	// Token: 0x040005B8 RID: 1464
	RightCurlyBracket,
	// Token: 0x040005B9 RID: 1465
	Tilde,
	// Token: 0x040005BA RID: 1466
	Numlock = 300,
	// Token: 0x040005BB RID: 1467
	CapsLock,
	// Token: 0x040005BC RID: 1468
	ScrollLock,
	// Token: 0x040005BD RID: 1469
	RightShift,
	// Token: 0x040005BE RID: 1470
	LeftShift,
	// Token: 0x040005BF RID: 1471
	RightControl,
	// Token: 0x040005C0 RID: 1472
	LeftControl,
	// Token: 0x040005C1 RID: 1473
	RightAlt,
	// Token: 0x040005C2 RID: 1474
	LeftAlt,
	// Token: 0x040005C3 RID: 1475
	LeftCommand = 310,
	// Token: 0x040005C4 RID: 1476
	LeftApple = 310,
	// Token: 0x040005C5 RID: 1477
	LeftWindows,
	// Token: 0x040005C6 RID: 1478
	RightCommand = 309,
	// Token: 0x040005C7 RID: 1479
	RightApple = 309,
	// Token: 0x040005C8 RID: 1480
	RightWindows = 312,
	// Token: 0x040005C9 RID: 1481
	AltGr,
	// Token: 0x040005CA RID: 1482
	Help = 315,
	// Token: 0x040005CB RID: 1483
	Print,
	// Token: 0x040005CC RID: 1484
	SysReq,
	// Token: 0x040005CD RID: 1485
	Break,
	// Token: 0x040005CE RID: 1486
	Menu,
	// Token: 0x040005CF RID: 1487
	Mouse0 = 323,
	// Token: 0x040005D0 RID: 1488
	Mouse1,
	// Token: 0x040005D1 RID: 1489
	Mouse2,
	// Token: 0x040005D2 RID: 1490
	Mouse3,
	// Token: 0x040005D3 RID: 1491
	Mouse4,
	// Token: 0x040005D4 RID: 1492
	Mouse5,
	// Token: 0x040005D5 RID: 1493
	Mouse6,
	// Token: 0x040005D6 RID: 1494
	JoystickButton0,
	// Token: 0x040005D7 RID: 1495
	JoystickButton1,
	// Token: 0x040005D8 RID: 1496
	JoystickButton2,
	// Token: 0x040005D9 RID: 1497
	JoystickButton3,
	// Token: 0x040005DA RID: 1498
	JoystickButton4,
	// Token: 0x040005DB RID: 1499
	JoystickButton5,
	// Token: 0x040005DC RID: 1500
	JoystickButton6,
	// Token: 0x040005DD RID: 1501
	JoystickButton7,
	// Token: 0x040005DE RID: 1502
	JoystickButton8,
	// Token: 0x040005DF RID: 1503
	JoystickButton9,
	// Token: 0x040005E0 RID: 1504
	JoystickButton10,
	// Token: 0x040005E1 RID: 1505
	JoystickButton11,
	// Token: 0x040005E2 RID: 1506
	JoystickButton12,
	// Token: 0x040005E3 RID: 1507
	JoystickButton13,
	// Token: 0x040005E4 RID: 1508
	JoystickButton14,
	// Token: 0x040005E5 RID: 1509
	JoystickButton15,
	// Token: 0x040005E6 RID: 1510
	JoystickButton16,
	// Token: 0x040005E7 RID: 1511
	JoystickButton17,
	// Token: 0x040005E8 RID: 1512
	JoystickButton18,
	// Token: 0x040005E9 RID: 1513
	JoystickButton19,
	// Token: 0x040005EA RID: 1514
	Joystick1Button0,
	// Token: 0x040005EB RID: 1515
	Joystick1Button1,
	// Token: 0x040005EC RID: 1516
	Joystick1Button2,
	// Token: 0x040005ED RID: 1517
	Joystick1Button3,
	// Token: 0x040005EE RID: 1518
	Joystick1Button4,
	// Token: 0x040005EF RID: 1519
	Joystick1Button5,
	// Token: 0x040005F0 RID: 1520
	Joystick1Button6,
	// Token: 0x040005F1 RID: 1521
	Joystick1Button7,
	// Token: 0x040005F2 RID: 1522
	Joystick1Button8,
	// Token: 0x040005F3 RID: 1523
	Joystick1Button9,
	// Token: 0x040005F4 RID: 1524
	Joystick1Button10,
	// Token: 0x040005F5 RID: 1525
	Joystick1Button11,
	// Token: 0x040005F6 RID: 1526
	Joystick1Button12,
	// Token: 0x040005F7 RID: 1527
	Joystick1Button13,
	// Token: 0x040005F8 RID: 1528
	Joystick1Button14,
	// Token: 0x040005F9 RID: 1529
	Joystick1Button15,
	// Token: 0x040005FA RID: 1530
	Joystick1Button16,
	// Token: 0x040005FB RID: 1531
	Joystick1Button17,
	// Token: 0x040005FC RID: 1532
	Joystick1Button18,
	// Token: 0x040005FD RID: 1533
	Joystick1Button19,
	// Token: 0x040005FE RID: 1534
	Joystick2Button0,
	// Token: 0x040005FF RID: 1535
	Joystick2Button1,
	// Token: 0x04000600 RID: 1536
	Joystick2Button2,
	// Token: 0x04000601 RID: 1537
	Joystick2Button3,
	// Token: 0x04000602 RID: 1538
	Joystick2Button4,
	// Token: 0x04000603 RID: 1539
	Joystick2Button5,
	// Token: 0x04000604 RID: 1540
	Joystick2Button6,
	// Token: 0x04000605 RID: 1541
	Joystick2Button7,
	// Token: 0x04000606 RID: 1542
	Joystick2Button8,
	// Token: 0x04000607 RID: 1543
	Joystick2Button9,
	// Token: 0x04000608 RID: 1544
	Joystick2Button10,
	// Token: 0x04000609 RID: 1545
	Joystick2Button11,
	// Token: 0x0400060A RID: 1546
	Joystick2Button12,
	// Token: 0x0400060B RID: 1547
	Joystick2Button13,
	// Token: 0x0400060C RID: 1548
	Joystick2Button14,
	// Token: 0x0400060D RID: 1549
	Joystick2Button15,
	// Token: 0x0400060E RID: 1550
	Joystick2Button16,
	// Token: 0x0400060F RID: 1551
	Joystick2Button17,
	// Token: 0x04000610 RID: 1552
	Joystick2Button18,
	// Token: 0x04000611 RID: 1553
	Joystick2Button19,
	// Token: 0x04000612 RID: 1554
	Joystick3Button0,
	// Token: 0x04000613 RID: 1555
	Joystick3Button1,
	// Token: 0x04000614 RID: 1556
	Joystick3Button2,
	// Token: 0x04000615 RID: 1557
	Joystick3Button3,
	// Token: 0x04000616 RID: 1558
	Joystick3Button4,
	// Token: 0x04000617 RID: 1559
	Joystick3Button5,
	// Token: 0x04000618 RID: 1560
	Joystick3Button6,
	// Token: 0x04000619 RID: 1561
	Joystick3Button7,
	// Token: 0x0400061A RID: 1562
	Joystick3Button8,
	// Token: 0x0400061B RID: 1563
	Joystick3Button9,
	// Token: 0x0400061C RID: 1564
	Joystick3Button10,
	// Token: 0x0400061D RID: 1565
	Joystick3Button11,
	// Token: 0x0400061E RID: 1566
	Joystick3Button12,
	// Token: 0x0400061F RID: 1567
	Joystick3Button13,
	// Token: 0x04000620 RID: 1568
	Joystick3Button14,
	// Token: 0x04000621 RID: 1569
	Joystick3Button15,
	// Token: 0x04000622 RID: 1570
	Joystick3Button16,
	// Token: 0x04000623 RID: 1571
	Joystick3Button17,
	// Token: 0x04000624 RID: 1572
	Joystick3Button18,
	// Token: 0x04000625 RID: 1573
	Joystick3Button19,
	// Token: 0x04000626 RID: 1574
	Joystick4Button0,
	// Token: 0x04000627 RID: 1575
	Joystick4Button1,
	// Token: 0x04000628 RID: 1576
	Joystick4Button2,
	// Token: 0x04000629 RID: 1577
	Joystick4Button3,
	// Token: 0x0400062A RID: 1578
	Joystick4Button4,
	// Token: 0x0400062B RID: 1579
	Joystick4Button5,
	// Token: 0x0400062C RID: 1580
	Joystick4Button6,
	// Token: 0x0400062D RID: 1581
	Joystick4Button7,
	// Token: 0x0400062E RID: 1582
	Joystick4Button8,
	// Token: 0x0400062F RID: 1583
	Joystick4Button9,
	// Token: 0x04000630 RID: 1584
	Joystick4Button10,
	// Token: 0x04000631 RID: 1585
	Joystick4Button11,
	// Token: 0x04000632 RID: 1586
	Joystick4Button12,
	// Token: 0x04000633 RID: 1587
	Joystick4Button13,
	// Token: 0x04000634 RID: 1588
	Joystick4Button14,
	// Token: 0x04000635 RID: 1589
	Joystick4Button15,
	// Token: 0x04000636 RID: 1590
	Joystick4Button16,
	// Token: 0x04000637 RID: 1591
	Joystick4Button17,
	// Token: 0x04000638 RID: 1592
	Joystick4Button18,
	// Token: 0x04000639 RID: 1593
	Joystick4Button19,
	// Token: 0x0400063A RID: 1594
	Joystick5Button0,
	// Token: 0x0400063B RID: 1595
	Joystick5Button1,
	// Token: 0x0400063C RID: 1596
	Joystick5Button2,
	// Token: 0x0400063D RID: 1597
	Joystick5Button3,
	// Token: 0x0400063E RID: 1598
	Joystick5Button4,
	// Token: 0x0400063F RID: 1599
	Joystick5Button5,
	// Token: 0x04000640 RID: 1600
	Joystick5Button6,
	// Token: 0x04000641 RID: 1601
	Joystick5Button7,
	// Token: 0x04000642 RID: 1602
	Joystick5Button8,
	// Token: 0x04000643 RID: 1603
	Joystick5Button9,
	// Token: 0x04000644 RID: 1604
	Joystick5Button10,
	// Token: 0x04000645 RID: 1605
	Joystick5Button11,
	// Token: 0x04000646 RID: 1606
	Joystick5Button12,
	// Token: 0x04000647 RID: 1607
	Joystick5Button13,
	// Token: 0x04000648 RID: 1608
	Joystick5Button14,
	// Token: 0x04000649 RID: 1609
	Joystick5Button15,
	// Token: 0x0400064A RID: 1610
	Joystick5Button16,
	// Token: 0x0400064B RID: 1611
	Joystick5Button17,
	// Token: 0x0400064C RID: 1612
	Joystick5Button18,
	// Token: 0x0400064D RID: 1613
	Joystick5Button19,
	// Token: 0x0400064E RID: 1614
	Joystick6Button0,
	// Token: 0x0400064F RID: 1615
	Joystick6Button1,
	// Token: 0x04000650 RID: 1616
	Joystick6Button2,
	// Token: 0x04000651 RID: 1617
	Joystick6Button3,
	// Token: 0x04000652 RID: 1618
	Joystick6Button4,
	// Token: 0x04000653 RID: 1619
	Joystick6Button5,
	// Token: 0x04000654 RID: 1620
	Joystick6Button6,
	// Token: 0x04000655 RID: 1621
	Joystick6Button7,
	// Token: 0x04000656 RID: 1622
	Joystick6Button8,
	// Token: 0x04000657 RID: 1623
	Joystick6Button9,
	// Token: 0x04000658 RID: 1624
	Joystick6Button10,
	// Token: 0x04000659 RID: 1625
	Joystick6Button11,
	// Token: 0x0400065A RID: 1626
	Joystick6Button12,
	// Token: 0x0400065B RID: 1627
	Joystick6Button13,
	// Token: 0x0400065C RID: 1628
	Joystick6Button14,
	// Token: 0x0400065D RID: 1629
	Joystick6Button15,
	// Token: 0x0400065E RID: 1630
	Joystick6Button16,
	// Token: 0x0400065F RID: 1631
	Joystick6Button17,
	// Token: 0x04000660 RID: 1632
	Joystick6Button18,
	// Token: 0x04000661 RID: 1633
	Joystick6Button19,
	// Token: 0x04000662 RID: 1634
	Joystick7Button0,
	// Token: 0x04000663 RID: 1635
	Joystick7Button1,
	// Token: 0x04000664 RID: 1636
	Joystick7Button2,
	// Token: 0x04000665 RID: 1637
	Joystick7Button3,
	// Token: 0x04000666 RID: 1638
	Joystick7Button4,
	// Token: 0x04000667 RID: 1639
	Joystick7Button5,
	// Token: 0x04000668 RID: 1640
	Joystick7Button6,
	// Token: 0x04000669 RID: 1641
	Joystick7Button7,
	// Token: 0x0400066A RID: 1642
	Joystick7Button8,
	// Token: 0x0400066B RID: 1643
	Joystick7Button9,
	// Token: 0x0400066C RID: 1644
	Joystick7Button10,
	// Token: 0x0400066D RID: 1645
	Joystick7Button11,
	// Token: 0x0400066E RID: 1646
	Joystick7Button12,
	// Token: 0x0400066F RID: 1647
	Joystick7Button13,
	// Token: 0x04000670 RID: 1648
	Joystick7Button14,
	// Token: 0x04000671 RID: 1649
	Joystick7Button15,
	// Token: 0x04000672 RID: 1650
	Joystick7Button16,
	// Token: 0x04000673 RID: 1651
	Joystick7Button17,
	// Token: 0x04000674 RID: 1652
	Joystick7Button18,
	// Token: 0x04000675 RID: 1653
	Joystick7Button19,
	// Token: 0x04000676 RID: 1654
	Joystick8Button0,
	// Token: 0x04000677 RID: 1655
	Joystick8Button1,
	// Token: 0x04000678 RID: 1656
	Joystick8Button2,
	// Token: 0x04000679 RID: 1657
	Joystick8Button3,
	// Token: 0x0400067A RID: 1658
	Joystick8Button4,
	// Token: 0x0400067B RID: 1659
	Joystick8Button5,
	// Token: 0x0400067C RID: 1660
	Joystick8Button6,
	// Token: 0x0400067D RID: 1661
	Joystick8Button7,
	// Token: 0x0400067E RID: 1662
	Joystick8Button8,
	// Token: 0x0400067F RID: 1663
	Joystick8Button9,
	// Token: 0x04000680 RID: 1664
	Joystick8Button10,
	// Token: 0x04000681 RID: 1665
	Joystick8Button11,
	// Token: 0x04000682 RID: 1666
	Joystick8Button12,
	// Token: 0x04000683 RID: 1667
	Joystick8Button13,
	// Token: 0x04000684 RID: 1668
	Joystick8Button14,
	// Token: 0x04000685 RID: 1669
	Joystick8Button15,
	// Token: 0x04000686 RID: 1670
	Joystick8Button16,
	// Token: 0x04000687 RID: 1671
	Joystick8Button17,
	// Token: 0x04000688 RID: 1672
	Joystick8Button18,
	// Token: 0x04000689 RID: 1673
	Joystick8Button19
};

inline bool GetKeyDownString(std::string name)
{
	auto il2cppstr = IL2CPP::StringNew(name);

	using func_t = bool(*)(IL2CPP::String* name);

	func_t func = GetMethod<func_t>(GETKEYDOWNSTRING);

	return func(il2cppstr);
}

inline bool GetKeyDown(KeyCode name)
{
	using func_t = bool(*)(int32_t key);

	func_t func = GetMethod<func_t>(0x1C9FE90);

	return func(name);
}

inline bool GetKey(KeyCode name)
{
	using func_t = bool(*)(int32_t key);

	func_t func = GetMethod<func_t>(GETKEYPRESSED);

	return func(name);
}

// RVA: 0x1C9FCC0 Offset: 0x1C9E6C0 VA: 0x181C9FCC0
inline float GetAxis(std::string axisName) 
{
	using func_t = float(*)(IL2CPP::String* axisName);

	func_t func = GetMethod<func_t>(INPUT_GETAXIS);

	return func(IL2CPP::StringNew(axisName));
}