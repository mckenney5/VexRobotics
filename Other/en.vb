Imports System.Console
Public Class en
Public Shared Sub Main()
	Console.WriteLine("Please enter the distance in inches")
	Do While (true)
	Try
		Dim D As Integer
		Dim C As Decimal = "12.9590697"
		Dim Wr As Decimal
		Dim Ma As Decimal = 2/3
		Dim Mr As Decimal
		Dim Mt As Decimal = "627.2"
		Dim E
		Console.Write("> ")
		D = Console.Readline()
		Console.WriteLine("Computing...")
		Wr = C / D
		Mr = Wr / Ma
		E = Mr * Mt
		Console.Writeline("Encoder Tics: " & E)
	Catch
		Console.WriteLine("Error (" & Err.Number & ") " & Err.Description)
	End Try
	'Console.ReadLine()
	Loop
End Sub
End Class
