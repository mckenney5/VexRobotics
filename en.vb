Imports System.Console

Public Class en

Public Shared Sub Main()

	Try

		Dim D As Integer

		Dim C As Decimal = "12.9590697"

		Dim Wr As Decimal

		Dim Ma As Decimal = "0.6666666666666667"

		Dim Mr As Decimal

		Dim Mt As Decimal = "627.2"

		Dim E

		Console.WriteLine("Please enter the distance in inches OR type man")

		Console.Write("> ")

		D = Console.Readline()

		Console.WriteLine("Computing...")

		Wr = D / C

		Mr = Wr / Ma

		E = Mr * Mt

		Console.Writeline("Encoder Tics: " & E)

	Catch

		Console.WriteLine("Error (" & Err.Number & ") " & Err.Description)
	End Try

	Console.ReadLine()

End Sub

End Class